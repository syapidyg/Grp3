--  | __________________________________________________________________________________________________________________
-- BDD ACAR | __________________________________________________________________________________________________________________
--  | __________________________________________________________________________________________________________________

DROP DATABASE acar;
CREATE DATABASE IF NOT EXISTS acar;
USE acar;

--  | __________________________________________________________________________________________________________________
-- TABLES | __________________________________________________________________________________________________________________
--  | __________________________________________________________________________________________________________________

-- VILLE _________________________________________________________________________________
CREATE TABLE `x&	Ville` (
	`id_ville ` INT NOT NULL AUTO_INCREMENT ,
    `structure` char (30) NOT NULL,				-- Stockage des informations sur la structure de la ville
    `coord_x` char (100) NOT NULL,			-- Données générales sur la ville
    `coord_y` char (1) NOT NULL,			-- Référencement des places disponibles dans la ville.
      
      PRIMARY KEY (id_ville)
)

ENGINE=InnoDB DEFAULT CHARSET=latin1;
	
INSERT INTO `Ville` (`structure`, `coord_x`, `coord_y`)

VALUES
( 'route' ,'0' ,'0'),
( 'route' ,'0' ,'0');

-- UTILISATEUR ___________________________________________________________________________
CREATE TABLE `Utilisateur` (
	`id_user` INT NOT NULL AUTO_INCREMENT,
	`nom` CHAR (30) NOT NULL,
    `prenom` CHAR (30) NOT NULL,
    
    PRIMARY KEY (id_user)
)

ENGINE=InnoDB DEFAULT CHARSET=latin1;

INSERT INTO `Utilisateur` (`nom`, `prenom`) VALUES
	('CLEMENT', 'Thomas'),
	('BOUDRINGHIN', 'Jonathan'),
    ('DECROIX', 'Gaël'),
    ('FICOT', 'Paul');


-- VEHICULE ______________________________________________________________________________
CREATE TABLE `Vehicule` (
	`immatriculation` VARCHAR (9) NOT NULL,
	`modele` CHAR (20) NOT NULL,
    `longueur` INT (10) NOT NULL,
    `largueur` INT (10) NOT NULL,
    `hauteur` INT (10) NOT NULL,
    `constructeur` char (30) NOT NULL,
    
    PRIMARY KEY (immatriculation)
)
                        
ENGINE=InnoDB DEFAULT CHARSET=latin1;

INSERT INTO `Vehicule` (`immatriculation`, `modele`, `longueur`, `largueur`, `hauteur`, `constructeur`) VALUES
	('AA-111-AA', 'A',1 ,1 ,1 ,'A'),
    ('BB-222-BB', 'B',2 ,2 ,2 ,'B'),
    ('CC-333-CC', 'C',3 ,3 ,3 ,'C'),
    ('DD-444-DD', 'D',4 ,4 ,4 ,'D'),
    ('EE-555-EE', 'E',5 ,5 ,5 ,'E');

-- DEPLACEMENTS __________________________________________________________________________
CREATE TABLE `Deplacements` (
	`id_deplacement` INT NOT NULL AUTO_INCREMENT,
	`pos_actuelle` CHAR (1) NOT NULL,
	`pos_deplacement` CHAR (1) NOT NULL,
    
    PRIMARY KEY (id_deplacement)
)	

ENGINE=InnoDB DEFAULT CHARSET=latin1;

INSERT INTO `Deplacements` (`pos_actuelle`, `pos_deplacement`)

VALUES
	('A', 'B'),
	('A', 'M'),
	('B', 'A'),
	('B', 'J'),
	('B', 'C'),
	('C', 'B'),
	('C', 'D'),
	('C', 'F'),
	('D', 'C'),
	('D', 'E'),
	('E', 'D'),
	('E', 'F'),
	('E', 'H'),
	('F', 'C'),
	('F', 'E'),
	('F', 'G'),
    ('G', 'F'),
    ('G', 'H'),
    ('H', 'G'),
    ('H', 'E'),
    ('H', 'I'),
    ('I', 'H'),
    ('I', 'J'),
    ('I', 'P'),
    ('J', 'I'),
    ('J', 'B'),
    ('J', 'O'),
    ('J', 'K'),
    ('K', 'J'),
    ('K', 'L'),
    ('L', 'K'),
    ('L', 'M'),
    ('M', 'L'),
    ('M', 'A'),
    ('M', 'N'),
    ('N', 'M'),
    ('N', 'O'),
    ('O', 'N'),
    ('O', 'P'),
    ('O', 'J'),
    ('P', 'O'),
    ('P', 'I');


-- POOL DEMANDE  _________________________________________________________________________
CREATE TABLE `Pool_demande` (
	`id_demande` INT NOT NULL AUTO_INCREMENT,
    `provenance` CHAR (1) NOT NULL,
    `destination` CHAR (1) NOT NULL,
    
    PRIMARY KEY (id_demande)
)

ENGINE=InnoDB DEFAULT CHARSET=latin1;

INSERT INTO `Pool_demande` (`id_demande`, `provenance`, `destination`)

VALUES
	('', '');


-- STATIONNEMENT _________________________________________________________________________
CREATE TABLE `Stationnement` (
	`id_place` INT NOT NULL AUTO_INCREMENT,
	`x_place` int (1) NOT NULL,
	`y_place` int (1) NOT NULL,
    `longueur_place` int (1) NOT NULL,
    `largueur_place` int (1) NOT NULL,
    
    PRIMARY KEY (id_place)
)

ENGINE=InnoDB DEFAULT CHARSET=latin1;

INSERT INTO `Stationnement` (`x_place`, `y_place`, `longueur_place`, `largueur_place`)

VALUES
	(1 ,3 ,5 ,12 ,8 );


-- HISTORIQUE ____________________________________________________________________________
CREATE TABLE `Historique` (
	`id_mvt` INT NOT NULL AUTO_INCREMENT,
	`type_mvt` CHAR (20) NOT NULL,
        
        PRIMARY KEY (deplacement)
)

ENGINE=InnoDB DEFAULT CHARSET=latin1;

