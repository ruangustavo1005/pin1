<?php

/**
 * Persistência Padrão
 *
 * @author Leonardo Alex Fusinato
 */
class Persistencia {
    
    /** @var \PDO */
    protected $Query;
    
    public function getQuery(): \Query {
        return $this->Query;
    }
    
    public function __construct() {
        try {
            $this->Query = new PDO('pgsql:host=localhost;dbname=pin1;', 'root', 123); 
        } catch (PDOException $e) {
            echo 'Erro ao se conectar ao banco: ' . $e->getMessage();
        }
    }
    
}