select m.machine_id, round(avg(a.timestamp - m.timestamp),3) processing_time  from Activity m
join Activity a on m.machine_id = a.machine_id
and m.process_id = a.process_id 
and m.activity_type='start' 
and a.activity_type='end'
group by machine_id;

