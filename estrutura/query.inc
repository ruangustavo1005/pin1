<?php

/**
 * Classe para querys no site
 *
 * @author Leonardo Alex Fusinato
 */
class Query {
 
    /** @var PDO */
    private $pdo;
    private $sql;
    
    public function __construct() {
        $this->pdo = $this->criaConexao();
        return $this->pdo;
    }
    
    /**
     * Cria e realiza a conexão com o banco de dados
     */
    private function criaConexao() {
        try {
            return new PDO('pgsql:host=localhost;dbname=pin1;', 'root', 123); 
        } catch (PDOException $e) {
            echo 'Erro ao se conectar ao banco: ' . $e->getMessage();
        }
    }
    
}