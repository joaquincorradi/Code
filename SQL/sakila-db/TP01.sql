use sakila;

-- Ejercicio 01
SELECT *
FROM actor;

-- Ejercicio 02
SELECT first_name as Nombre, last_name as Apellido
FROM actor;

-- Ejercicio 03
SELECT first_name as Nombre
FROM actor
ORDER BY Nombre desc;

-- Ejercicio 04
SELECT title, rating
FROM film
WHERE rating = "PG" or rating = "R";

-- Ejercicio 05
SELECT title, length, rating
FROM film
WHERE length >= 120 and rating = "G";

-- Ejercicio 06
SELECT film.title, film.length, language.name
FROM film, language
WHERE film.language_id = language.language_id
	AND film.length >= 120
	AND language.name = "French";

-- Ejercicio 07
SELECT film.title, film.length, language.name
FROM film, language
WHERE film.language_id = language.language_id
	AND film.length >= 120
	AND language.name = "English"
ORDER BY film.length;

-- Ejercicio 08
SELECT first_name, last_name, active
FROM customer
WHERE active = 1;

-- Ejercicio 09
SELECT amount * 0.90
FROM payment;

-- Ejercicio 10
SELECT actor.first_name, actor.last_name, film.title
FROM film_actor, film, actor
WHERE film_actor.film_id = film.film_id
	AND film_actor.actor_id = actor.actor_id;

-- Ejercicio 11
SELECT actor.first_name, actor.last_name, film.title, film.release_year, film.length
FROM film_actor, film, actor
WHERE film_actor.film_id = film.film_id
	AND film_actor.actor_id = actor.actor_id
	AND film.release_year < 1990
ORDER BY film.length;

-- Ejercicio 12
SELECT film.title, rental.rental_date, category.name
FROM rental, inventory, film_category as fc, category, film
WHERE rental.inventory_id = inventory.inventory_id
	AND inventory.film_id = fc.film_id
	AND fc.category_id = category.category_id
	AND category.name = "Drama"
	AND rental.rental_date >= "2005-01-01"
	AND rental.rental_date <= "2005-12-31";

-- Ejercicio 13
SELECT COUNT(*) as "Cant. alquileres"
FROM rental;

-- Ejercicio 14
SELECT title, length
FROM film
ORDER BY length desc
LIMIT 1;

-- Ejercicio 15
SELECT 
FROM payment