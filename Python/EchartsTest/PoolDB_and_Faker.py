'''
Created on 2019年7月28日

@author: 70425
'''
from DBUtils.PooledDB import  PooledDB
from faker import Faker
import MySQLdb

pool = PooledDB(MySQLdb,5,host='localhost',user='root',db='EchartsTest',passwd='197401',port=3306,charset='utf8')

con = pool.connection()
cur = con.cursor()

for i in range(100):
    f = Faker('zh_CN')
    if i%2==0:
        Sex='男'
    else:
        Sex='女'
    Sql = "insert into MyData(姓名,年龄,性别,工资) values('%s',%d,'%s',%f)"%(f.name(),f.random_number(digits=2),Sex,f.random_number(digits=4))
    cur.execute(Sql)
    con.commit()

cur.execute('select * from MyData')
r = cur.fetchall()
print('序号\t姓名\t年龄\t性别\t工资')
for i in r:
    Num = i[0]
    Name = i[1]
    Age = i[2]
    Sex = i[3]
    Salary = i[4]
    print(Num,'\t',Name,'\t',Age,'\t',Sex+'\t',Salary)

cur.close()
con.close()
