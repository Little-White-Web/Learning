'''
Created on 2019年7月22日

@author: 70425
'''
from DBUtils.PooledDB import  PooledDB
import MySQLdb
from pyecharts.charts import Pie,Page,Bar
from itertools import chain

pool = PooledDB(MySQLdb,5,host='localhost',user='root',db='EchartsTest',passwd='197401',port=3306,charset='utf8')

con = pool.connection()
cur = con.cursor()

Sql = "select 姓名 from mydata limit 10"
cur.execute(Sql)
Name = cur.fetchall()
Name = list(chain.from_iterable(Name))
print(Name)

Sql = "select 年龄 from mydata limit 10"
cur.execute(Sql)
Age = cur.fetchall()
Age = list(chain.from_iterable(Age))
print(Age)

Sql = "select 工资 from mydata limit 10"
cur.execute(Sql)
Salary = cur.fetchall()
Salary = list(chain.from_iterable(Salary))
print(Salary)

cur.close()
con.close()

bar = (Bar()
       .add_xaxis(Name)
       .add_yaxis("年龄",Age)
       )

pie = (Pie()
       .add("工资饼图",[list(z) for z in zip(Name,Salary)])
    )

page = (Page()
        .add(bar,pie)
        .render()
        )
