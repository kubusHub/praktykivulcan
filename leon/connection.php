<?php

 $serverName="L-01302018";
 $database = "sus";
 $uid = "";
 $pass = "";

 $connection = [
 "Database" => $database,
 "Uid" => $uid,
 "PWD" => $pass
 ];


$conn = sqlsrv_connect($serverName,$conection);
 if(!$conn)
 die(print_r(sqlsrv_errors(),true));
 else
echo'connection establised';

?>