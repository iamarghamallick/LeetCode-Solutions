# Write your MySQL query statement below
select st.student_id, st.student_name, sb.subject_name, count(ex.student_id) as attended_exams
from students st
join subjects sb
left join examinations ex
on ex.student_id = st.student_id
and ex.subject_name = sb.subject_name
group by st.student_id, sb.subject_name
order by st.student_id, sb.subject_name;