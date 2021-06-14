DELIMITER |

CREATE PROCEDURE  Insertion_mvt(IN id_mvt INT, IN type_mvt CHAR)

BEGIN  
		INSERT INTO Historique (type_mvt)
        
        VALUES (type_mvt);
END|


