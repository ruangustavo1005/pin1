<?php

require_once 'persistencia.inc';
require_once '../model/marca.inc';

/**
 * Persistência da Marca
 *
 * @author Leonardo Alex Fusinato
 */
class PersistenciaMarca extends Persistencia {
    
    
    /**
     * Retorna todas as marcas
     * 
     * @return Marca[]
     */
    public function getAllMarcas() {
        $sSql = "
            SELECT *
              FROM tbmarca
        ";
        $aMarcas = [];
        $oSql = $this->Query->query($sSql);
        foreach($oSql->fetchAll(PDO::FETCH_OBJ) as $oObject) {
            $oMarca = new Marca();
            $oMarca->setCodigo($oObject->marcodigo);
            $oMarca->setNome($oObject->marnome);
            $aMarcas[] = $oMarca;
        }
        return $aMarcas;
    }
    
}