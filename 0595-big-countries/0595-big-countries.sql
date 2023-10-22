# Using OR --->

#SELECT w.name, w.population, w.area FROM World w
#WHERE w.area >= 3000000 OR w.population >= 25000000;


# Using UNION --->

SELECT name, population, area
FROM World
WHERE area >= 3000000 

UNION

SELECT name, population, area
FROM World
WHERE population >= 25000000
