<?php
    function getTransactionFiles(string $dirPath): array{
        $files = [];

        foreach(scandir($dirPath) as $file){
            if(is_dir($file)){
                continue;
            }
            $files[]=$dirPath . $file;
            var_dump($file);
        }
        return $files;
    }
    function getTransactions(string $filename): array{
        if(! file_exists($fileName)){
            trigger_error('File "' . $fileName . '" does not exist', E_USER_ERROR);
        }
        $file = fopen($fileName, 'r');

        $transactions = [];
        while(($transaction = fgetcsv($file)) === false){
            $transactions[]=$transaction;
        }
        return $transactions;
    }
?>