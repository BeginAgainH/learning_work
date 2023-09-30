MySQL练习

![image-20230210102545599](C:\Users\82765\AppData\Roaming\Typora\typora-user-images\image-20230210102545599.png)

```
create table emp(
			name char(10),
			age int(3),
			job char(15),
			dep char(15),
			salary int(10),
			salary_level int(2),
			dep_id int(3)
			);

create table dep(
			dep_id int(3),
			name char(15)
	);

insert into emp
		values('张三',24,'员工','后勤部',5000,2,2),
		('李四',24,'员工','后勤部',5000,2,2),
		('王五',24,'员工','后勤部',6000,3,2),
		('赵六',27,'员工','研发部',6000,3,1),
		('陈七',36,'员工','研发部',8000,4,1),
		('灭绝',41,'员工','研发部',9000,5,1);

insert into dep
		values(1,'研发部'),
		(2,'后勤部');


alter table dep add emp_num int(3);

update dep set dep.emp_num=3 where dep.name='研发部';
update dep set dep.emp_num=3 where dep.name='后勤部';

select name,age,job,dep from emp where age<30;

select * from dep where dep.emp_num!=0;

select name,dep from emp where age>=40;

select salary_level from emp;
select * from emp where dep_id = 1;

alter table dep change dep_id id int(2);

alter table dep modify id int(3);

alter table dep add primary key (id);

alter table emp add constraint fk_emp foreign key(dep_id) references dep(id) on update cascade on delete cascade ;

select avg(salary) from emp where dep_id=1;

select * from emp where dep_id=1;

select * from emp where salary>(select  salary from emp where name = '灭绝');

select * from emp where salary>(select avg(salary) from emp);

select * from emp where salary<(select avg(salary) from emp);

create table slary_lev(
		sla_id int(2),
		level int(2),
		primary key(sla_id)
);

alter table slary_lev change level h_est int(8);
alter table slary_lev add l_est int(8);
alter table slary_lev change sla_id level int(2);

insert into slary_lev values (1,2000,0),(2,4000,2000),(3,6000,4000),(4,8000,6000);

create database class_sch;
use class_sch;
create table student (
        std_id int(5),
        std_name char(10),
        std_age int(2),
        std_


)
```





![image-20230430232636982](C:\Users\82765\AppData\Roaming\Typora\typora-user-images\image-20230430232636982.png)

```
select的嵌套,select的输出实际上是为一个新的表,所以select的嵌套需要用到表的链接
having可用聚合函数来判断,但WHERE不可以,因为group by后having是对group里的所有数据进行筛选,而WHERE是对查询结果进行分组前，将不符合where条件的行去掉

聚合函数只能在以下位置作为表达式使用：
select 语句的选择列表（子查询或外部查询）；
compute 或 compute by 子句；
having 子句；
```



![image-20230504233536680](C:\Users\82765\AppData\Roaming\Typora\typora-user-images\image-20230504233536680.png)

```
对数据添加新的标签可以用row_number() over()
row_number() over(partition 字段名1 order by 字段名2)
按字段名1分组,按字段名2排序,这里若partiontion不空则输出数据已经按照字段名1分组输出,相当于已经group by

count(1)等同于count(*),即
```

