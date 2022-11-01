--   1

--a)
select *
from course
where credits > 3;

--b)
select *
from classroom
where building = 'Watson'
   or building = 'Packard';

--c)
select *
from course
where dept_name = 'Comp. Sci.';

--d)
select *
from course
where course_id in (select course_id from section where semester = 'Fall');

--e)
select *
from student
where tot_cred > 45
  and tot_cred < 90;

--f)
select *
from student
where right(name, 1) in ('a', 'i', 'u', 'o', 'e');

--g)
select *
from course
where course_id in (select course_id
                    from prereq
                    where prereq_id = 'CS-101');



--  2
--a)
select avg(salary), dept_name
from instructor
group by dept_name
order by avg(salary);

--b)
select count(course_id), building
from section
group by building
limit 1;

--c)
select count(course_id), dept_name
from course
group by dept_name
limit 1;

--d)
select ID, name
from student
where ID in (select ID
             from takes
             where left(course_id, 2) in ('CS')
             group by id having count(*) > 3);

--f)
select *
from instructor
where id in (select id
             from teaches t
             where id not in (select id from teaches where year=2017)
             and t.year = 2018);


--  3
--a)
select *
from student
where id in (select id
             from takes
             where grade in ('A', 'A-'))
order by name;

--b)
select *
from advisor
where s_id in(select id
              from student
              where id in (select id
                           from takes
                           where grade not in ('A', 'A-', 'B+')));

--c)
select *
from department
where dept_name not in (select dept_name
                    from course
                    where course_id in (select course_id
                                        from takes
                                        where grade in ('C', 'F')))

--d)
select *
from instructor
where id not in (select distinct  id
                 from takes
                 where grade in ('A', 'A-'));

--e)
select *
from course
where course_id in (select course_id
                    from section
                    where time_slot_id in (select time_slot_id
                                           from time_slot
                                           where end_hr<13));



















select  *
from instructor
where id in(select id from teaches t where id not in(select  id from teaches where year=2017) and
                                         year = 2018)
