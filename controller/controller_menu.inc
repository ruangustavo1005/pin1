<?php

require_once '../view/view_search.inc';
require_once '../persistencia/persistencia_marca.inc';
require_once '../persistencia/persistencia_modelo.inc';

/**
 * Controller do Menu
 *
 * @author Leonardo Alex Fusinato
 */
class ControllerMenu {
    
    /** @var PersistenciaMarca */
    private $PersistenciaMarca;
    
    /** @var PersistenciaModelo */
    private $PersistenciaModelo;
    
    public function getPersistenciaMarca(): PersistenciaMarca {
        if(!isset($this->PersistenciaMarca)) {
            $this->PersistenciaMarca = new PersistenciaMarca();
        }
        return $this->PersistenciaMarca;
    }

    public function getPersistenciaModelo(): PersistenciaModelo {
        if(!isset($this->PersistenciaModelo)) {
            $this->PersistenciaModelo = new PersistenciaModelo();
        }
        return $this->PersistenciaModelo;
    }
        
    public function getHtmlSearch() {
        $oView = new ViewSearch();
        return $oView->getCamposPesquisa($this->getPersistenciaMarca()->getAllMarcas(), $this->getPersistenciaModelo()->getAllModelos());
    }
    
}