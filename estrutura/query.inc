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
        $sConnection = "host=localhost port=5432 dbname=pin1 user=root password=123";
        $oConexao = pg_connect($sConnection);
        if(!$oConexao) {
            die('Não foi possível conectar-se com o banco.');
        } else {
            return $oConexao;
        }
    }
    
}