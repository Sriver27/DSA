# Write your MySQL query statement below


# Since Each student from the Students table takes every course from the Subjects table ---> we have to cross join students and subjects table
SELECT s.student_id, s.student_name, sb.subject_name, ifnull(count(e.subject_name),0) AS attended_exams
FROM Students s CROSS JOIN Subjects sb
LEFT JOIN Examinations e
ON s.student_id = e.student_id AND e.subject_name = sb.subject_name
GROUP BY s.student_id, s.student_name, sb.subject_name
ORDER BY s.student_id, sb.subject_name;

