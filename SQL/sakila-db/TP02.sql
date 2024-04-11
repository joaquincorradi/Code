use sakila;

-- Ejercicio 01
SELECT
    SUM(amount) as Total_pagos
FROM
    payment;

-- Ejercicio 02
SELECT
    staff_id,
    SUM(amount) as Total_empleado_USD
FROM
    payment
GROUP BY
    staff_id;

-- Ejercicio 03
SELECT
    staff_id,
    SUM(amount)*1000 as Total_empleado_ARS
FROM
    payment
GROUP BY
    staff_id;

-- Ejercicio 04
SELECT
    staff.first_name,
    staff.last_name,
    SUM(amount) as Total_empleado_USD
FROM
    payment
INNER JOIN
        staff ON payment.staff_id = staff.staff_id
GROUP BY
    staff.staff_id;

-- Ejercicio 05
SELECT
    staff.first_name,
    staff.last_name,
    SUM(amount) as Total_empleado_USD
FROM
    payment
INNER JOIN
        staff ON payment.staff_id = staff.staff_id
WHERE
    YEAR(payment_date) = 2006
GROUP BY
    staff.staff_id;

-- Ejercicio 06
SELECT
    staff.first_name,
    staff.last_name,
    SUM(amount) as Total_empleado_USD
FROM
    payment
INNER JOIN
        staff ON payment.staff_id = staff.staff_id
WHERE
    YEAR(payment.payment_date) = 2006
GROUP BY
    staff.staff_id,
    staff.last_name
ORDER BY
    staff.last_name DESC;

-- Ejercicio 07
SELECT
    staff.first_name,
    staff.last_name,
    SUM(amount) as Total_empleado_USD
FROM
    payment
INNER JOIN
        staff ON payment.staff_id = staff.staff_id
WHERE
    YEAR(payment.payment_date) = 2006
  AND payment.amount > 2.5
GROUP BY
    staff.staff_id,
    staff.last_name
ORDER BY
    staff.last_name DESC;

-- Ejercicio 08
SELECT
    staff.first_name,
    staff.last_name,
    SUM(amount) as Total_empleado_USD
FROM
    payment
INNER JOIN
        staff ON payment.staff_id = staff.staff_id
WHERE
    YEAR(payment.payment_date) = 2006
  AND payment.amount > 2.5
GROUP BY
    staff.staff_id,
    staff.last_name
ORDER BY
    Total_empleado_USD DESC;

-- Ejercicio 09
SELECT
    staff.first_name,
    staff.last_name,
    SUM(amount) as Total_empleado_USD
FROM
    payment
INNER JOIN
        staff ON payment.staff_id = staff.staff_id
WHERE
    YEAR(payment.payment_date) = 2006
  AND payment.amount > 2.5
GROUP BY
    staff.staff_id,
    staff.last_name
HAVING
    Total_empleado_USD > 200;

-- Ejercicio 10
SELECT
    YEAR(rental_date) as fecha,
    COUNT(*) as cant_alq
FROM
    rental
GROUP BY
    YEAR(rental_date);

-- Ejercicio 11
SELECT
    MONTH(rental_date),
    YEAR(rental_date),
    COUNT(*) as cant_alq
FROM
    rental
GROUP BY
    MONTH(rental_date),
    YEAR(rental_date);

-- Ejercicio 12
SELECT
    MONTH(rental_date),
    YEAR(rental_date),
    COUNT(*) as cant_alq
FROM
    rental
WHERE
    YEAR(rental_date) = 2005
GROUP BY
    MONTH(rental_date),
    YEAR(rental_date);

-- Ejercicio 13
SELECT
    MONTH(rental_date),
    YEAR(rental_date),
    COUNT(*) as cant_alq
FROM
    rental
WHERE
    YEAR(rental_date) = 2005
GROUP BY
    MONTH(rental_date),
    YEAR(rental_date)
HAVING
    COUNT(*) >= 2000;

-- Ejercicio 14
SELECT
    MONTH(rental_date),
    YEAR(rental_date),
    COUNT(*) as cant_alq
FROM
    rental
WHERE
    YEAR(rental_date) = 2005
GROUP BY
    MONTH(rental_date),
    YEAR(rental_date)
HAVING
    COUNT(*) >= 2000
ORDER BY
    MONTH(rental_date) DESC;

-- Ejercicio 15
SELECT
    MIN(length) AS duracion,
    rating
FROM
    film
GROUP BY
    rating;

-- Ejercicio 16
SELECT
    rating,
    COUNT(*) as cantidad
FROM
    film
GROUP BY
    rating;

-- Ejercicio 17
SELECT
    language.name,
    COUNT(*) as cantidad
FROM
    film
INNER JOIN
        language ON film.language_id = language.language_id
GROUP BY
    language.name;

-- Ejercicio 18
SELECT
    category.name,
    COUNT(*) cantidad
FROM
    film_category
INNER JOIN
        category on film_category.category_id = category.category_id
GROUP BY
    film_category.category_id;

-- Ejercicio 19
SELECT
    language.name as idioma,
    film.rating,
    COUNT(*) AS cantidad
FROM
    film
INNER JOIN
        language ON film.language_id = language.language_id
GROUP BY
    language.name,
    film.rating

-- Ejercicio 20
SELECT
    language.name as idioma,
    category.name AS genero,
    COUNT(film.film_id) AS cantidad
FROM
    language
JOIN
        film ON language.language_id = film.language_id
JOIN
        film_category ON film.film_id = film_category.film_id
JOIN
        category ON film_category.category_id = category.category_id
GROUP BY
    language.name, category.name;

-- Ejercicio 21
SELECT
    film.title as nombre_pelicula,
    COUNT(film_actor.actor_id) as cantidad
FROM
    film
JOIN
        film_actor ON film.film_id = film_actor.film_id
JOIN
        actor ON film_actor.actor_id = actor.actor_id
WHERE
    film.release_year > 1980
GROUP BY
    film.title
HAVING
    COUNT(film_actor.actor_id) > 10
ORDER BY
    COUNT(film_actor.actor_id) DESC;




