#include<iostream>
using namespace std;
#define MAX 50

class grad{
    public:
        grad(){
            name="张三";
            num=0;
            age=15;
            sex='F';
            score=0;
        }
        void setData(){
            cout<<endl;
            cout<<"设置信息！"<<endl;
            cout<<"姓名:";cin>>name;
            cout<<"学号:";cin>>num;
            cout<<"年龄:";cin>>age;
            cout<<"性别:";cin>>sex;
            cout<<"成绩:";cin>>score;
        }
        void printData(){
            cout<<endl;
            cout<<"姓名:"<<name<<endl;
            cout<<"学号:"<<num<<endl;
            cout<<"年龄:"<<age<<endl;
            cout<<"性别:"<<sex<<endl;
            cout<<"成绩:"<<score<<endl;
        }
        friend class UI;
    private:
        string name;
        long long num;
        int age;
        char sex;
        float score;
};

class UI{
    public:
        UI(){
            for(int i=0;i<MAX;i++){
                grad();
            }
        }
        void setUP(){
            int op;
            do{
                system("clear");
                cout<<"1.创建新的学生信息"<<endl;
                cout<<"2.查找学生信息"<<endl;
                cout<<"3.修改学生成绩"<<endl;
                cout<<"0.退出系统"<<endl;
                cout<<"输入指令:";cin>>op;
                switch (op){
                    case 1:create();break;
                    case 2:find();break;
                    case 3:setScore();break;
                    case 0:cout<<"退出成功！"<<endl;break;
                    default:cout<<"指令错误！"<<endl;break;
                }
                cout<<"回车继续！";cin.get();cin.get();
            }while(op);
        }
        void create(){
            for(int i=0;i<MAX;i++){
                if(box[i].num == 0){
                    box[i].setData();
                    for(int j=0;j<i;j++){
                        if(box[i].num == box[j].num){
                            printf("学号已存在！已默认置为0！\n");
                            box[i].num=0;
                            break;
                        }
                    }
                    if(box[i].age<15 || box[i].age>35){
                        printf("年龄只能在15到35之间，已默认置为15！\n");
                        box[i].age=15;
                    }
                    if(box[i].sex != 'F' && box[i].sex != 'M'){
                        printf("性别错误！已默认置为F!\n");
                        box[i].sex='F';
                    }
                    if(box[i].score<0 || box[i].score>100){
                        printf("成绩只能在0到100之间，已默认置为0！\n");
                        box[i].score=0;
                    }
                    break;
                }
            }
            printf("创建成功！\n");
        }
        void find(){
            long long n;
            cout<<endl<<"查找的学号:";cin>>n;
            for(int i=0;i<10;i++){
                if(box[i].num == n){
                    box[i].printData();
                    break;
                }
            }
        }
        void setScore(){
            long long n;
            cout<<endl<<"学号:";cin>>n;
            for(int i=0;i<MAX;i++){
                if(box[i].num == n){
                    box[i].printData();
                    cout<<"新成绩:";cin>>box[i].score;
                    cout<<"修改成功！"<<endl;
                    box[i].printData();
                    break;
                }
            }
        }
    private:
        grad box[MAX];
};

int main()
{
    UI ui;
    ui.setUP();
    return 0;
}
