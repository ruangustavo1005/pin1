<?php

require_once 'persistencia.inc';

/**
 * Persistência do Modelo
 *
 * @author Leonardo Alex Fusinato
 */
class PersistenciaModelo extends Persistencia {
 
    /**
     * Retorna todas os modelos
     * 
     * @return Modelo[]
     */
    public function getAllModelos() {
        $sSql = "
            SELECT *
              FROM tbmodelo
        ";
        $aModelos = [];
        $oSql = $this->Query->query($sSql);
        foreach($oSql->fetchAll(PDO::FETCH_OBJ) as $oObject) {
            $oModelo = new Modelo();
            $oModelo->getMarca()->setCodigo($oObject->marcodigo);
            $oModelo->setCodigo($oObject->modcodigo);
            $oModelo->setAno($oObject->modano);
            $oModelo->setNome($oObject->modnome);
            $aModelos[] = $oModelo;
        }
        return $aModelos;
    }
    
}