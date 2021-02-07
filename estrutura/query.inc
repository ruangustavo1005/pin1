<?php

/**
 * Classe para querys no site
 *
 * @author Leonardo Alex Fusinato
 */
class Query {
 
    private $conexao;
    private $sql;
    
    public function __construct() {
        $this->conexao = $this->criaConexao();
    }
    
    /**
     * Cria e realiza a conexão com o banco de dados
     */
    private function criaConexao() {
        $sConnection = "host=localhost port=5432 dbname=concessionaria_pin user=root password=123";
        if(!pg_connect($sConnection)) {
            die('Deu pau');
        }
    }
    
}