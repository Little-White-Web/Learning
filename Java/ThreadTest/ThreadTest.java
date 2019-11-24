import java.util.concurrent.locks.ReentrantReadWriteLock;
import java.util.concurrent.Executors;
import java.util.concurrent.ThreadPoolExecutor;

public class text {
	
	public static int count = 0;			//订单数

	public static void main(String[] args) throws InterruptedException {
		
		ThreadPoolExecutor executor;		//创建线程池
		executor = (ThreadPoolExecutor)Executors.newCachedThreadPool();	//实例为动态线程池
		//executor = (ThreadPoolExecutor)Executors.newFixedThreadPool(5);//实例为定长线程池
		
		for(int i=0;i<2;i++) {
			boss bos = new boss();		//创建boss对象
			works work = new works();	//创建works对象
			executor.execute(bos);		//boss对象进入线程池
			executor.execute(work);		//works对象进入线程池
		}
		executor.shutdown();			//关闭线程池
		
		System.out.println("线程池已关闭！");	//此条代码用于检验线程池是否已关闭
	}
	
}

class boss implements Runnable{				//boss类
	
	static final ReentrantReadWriteLock lock1 = new ReentrantReadWriteLock();//可重入读写锁
	boolean flag = true;				//置true开始循环
	
	public void run() {				//线程中执行的内容
		
		while(flag) {
			lock1.writeLock().lock();	//上锁（写锁）
			
			text.count++;			//增加订单（写数据）
			if(text.count>=9)
				flag = false;		//置false停止加订单
			System.out.println(Thread.currentThread().getName()+":订单+1");//打印提示信息
			
			lock1.writeLock().unlock();	//释放锁
			
			long time = (long)(Math.random()*1000);
			try {
				Thread.sleep(time);	//线程睡眠一段随机时长（其他线程才可访问或写数据）
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}
		
	}
}

class works implements Runnable{			//works类
	
	static final ReentrantReadWriteLock lock1 = new ReentrantReadWriteLock();//可重入读写锁
	boolean flag = true;				//置true开始循环
	
	public void run() {				//线程中执行的内容
		
		while(flag) {
			lock1.readLock().lock();	//上锁（读锁）
			
			if(text.count>=9)
				flag = false;		//置false停止查看订单
			System.out.println(Thread.currentThread().getName()+":当前订单数："+text.count);//打印提示信息
			
			lock1.readLock().unlock();	//释放锁
			
			long time = (long)(Math.random()*1000);
			try {
				Thread.sleep(time);	//线程睡眠一段随机时长（其他线程才可访问或读数据）
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}
		
	}

}
