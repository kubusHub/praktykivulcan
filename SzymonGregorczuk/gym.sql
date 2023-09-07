IF NOT EXISTS (
        SELECT *
        FROM sys.databases
        WHERE name = 'gym'
        )
BEGIN
    CREATE DATABASE gym
END
GO

USE gym
GO
IF OBJECT_ID(N'dbo.lokalizacje', N'U') IS NULL
CREATE TABLE lokalizacje(
	id int NOT NULL PRIMARY KEY,
	adres varchar,
	karta_id int FOREIGN KEY REFERENCES karty(karta_id),
	pracownik_id int FOREIGN KEY REFERENCES pracownicy(pracownik_id),
	wyposażenie_id int FOREIGN KEY REFERENCES wyposazenie(wyposazenie_id)
	);
IF OBJECT_ID(N'dbo.pracownicy', N'U') IS NULL
CREATE TABLE pracownicy(
	pracownik_id int NOT NULL PRIMARY KEY,
	PESEL int,
	imie varchar,
	nazwisko varchar,
	nr_telefonu int,
	mail varchar,
	pensja float,
	godziny_pracy varchar,
	posada varchar
	);
IF OBJECT_ID(N'dbo.karty', N'U') IS NULL
CREATE TABLE karty(
	karta_id int NOT NULL PRIMARY KEY,
	waznosc datetime2,
	data_godzina_wejscia datetime2,
	data_godzina_wyjscia datetime2
);
IF OBJECT_ID(N'dbo.klienci', N'U') IS NULL
CREATE TABLE klienci(
	klient_id int NOT NULL PRIMARY KEY,
	imie varchar,
	naziwsko varchar,
	karta_id int FOREIGN KEY REFERENCES karty(karta_id)
);
IF OBJECT_ID(N'dbo.wyposazenie', N'U') IS NULL
CREATE TABLE wyposazenie(
	wyposazenie_id int NOT NULL PRIMARY KEY,
	rodzaj_wyposażenia varchar,
	ilosc_wyposazenia integer,
);
