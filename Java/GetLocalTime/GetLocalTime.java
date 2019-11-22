import java.util.*;

public class GetLocalTime extends Thread { 
    public static void main(String[] args) { 
        Thread t=new Thread(){
            public void run(){
                while(true){
                    Calendar c=Calendar.getInstance();      
                    int Y=c.get(Calendar.YEAR);      
                    int M=c.get(Calendar.MONTH)+1;      
                    int D=c.get(Calendar.DATE);      
                    int h=c.get(Calendar.HOUR_OF_DAY);      
                    int m=c.get(Calendar.MINUTE);      
                    int s=c.get(Calendar.SECOND);      
                    System.out.printf(" Time:%4d.%02d.%02d    %02d:%02d:%02d    \r",Y,M,D,h,m,s);
                    try {
                        Thread.sleep(100);
                        } catch (InterruptedException e) {
                        e.printStackTrace();
                        }
                    }
            }
        };
        t.start();
    }
}
