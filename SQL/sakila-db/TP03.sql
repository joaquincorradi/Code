USE sakila;

-- Ejercicio 01
SELECT staff.first_name as nombre,
       staff.last_name as apellido,
       staff.email,
       address.address as direccion,
       address.district as districto,
       city.city as ciudad,
       address.phone as telefono
FROM staff
INNER JOIN store ON staff.staff_id = store.manager_staff_id
INNER JOIN address ON staff.address_id = address.address_id
INNER JOIN city on address.city_id = city.city_id;

-- Ejercicio 02
SELECT staff.first_name as nombre,
       staff.last_name as apellido,
       COUNT(*) as cant_alq
FROM rental
INNER JOIN staff ON rental.staff_id = staff.staff_id
GROUP BY staff.first_name,
         staff.last_name
ORDER BY staff.last_name DESC;

-- Ejercicio 03
SELECT staff.first_name as nombre,
       staff.last_name as apellido,
       COUNT(*) as total_pagos
FROM payment
INNER JOIN staff ON payment.staff_id = staff.staff_id
GROUP BY staff.first_name,
         staff.last_name;

-- Ejercicio 04
SELECT customer.first_name as nombre,
       customer.last_name as apellido,
       COUNT(*) AS cant_alq
FROM rental
INNER JOIN customer ON rental.customer_id = customer.customer_id
GROUP BY customer.first_name,
         customer.last_name
ORDER BY customer.last_name DESC;

-- Ejercicio 05
SELECT customer.first_name as nombre,
       customer.last_name as apellido
FROM customer
LEFT JOIN rental ON customer.customer_id = rental.customer_id
WHERE rental.rental_id IS NULL
ORDER BY customer.last_name DESC;

-- Ejercicio 06
SELECT customer.first_name AS nombre,
       customer.last_name AS apellido,
       SUM(payment.amount) AS total_gastado
FROM customer
INNER JOIN rental ON customer.customer_id = rental.customer_id
INNER JOIN payment ON rental.rental_id = payment.rental_id
GROUP BY customer.customer_id
ORDER BY total_gastado ASC;

-- Ejercicio 07
SELECT language.name AS idioma,
       COUNT(film_id) AS cant_peliculas
FROM language
LEFT JOIN film ON language.language_id = film.language_id
WHERE language.name = 'French'
   OR language.name = 'Italian'
   OR language.name = 'German'
GROUP BY language.name;

-- Ejercicio 08
SELECT language.name AS idioma,
       COUNT(film.film_id) AS cant_peliculas
FROM film
INNER JOIN language ON film.language_id = language.language_id
GROUP BY language.name;

-- Ejercicio 09
SELECT
  film.title AS titulo,
  language.name AS idioma
FROM film
INNER JOIN language ON film.language_id = language.language_id
WHERE language.name IN ('French', 'Italian');

-- Ejercicio 10
SELECT customer.first_name AS nombre,
       customer.last_name AS apellido,
       address.district
FROM customer
INNER JOIN address ON customer.address_id = address.address_id
WHERE address.district != 'California'
ORDER BY address.district ASC;
