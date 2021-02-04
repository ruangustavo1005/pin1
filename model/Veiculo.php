<?php

/**
 * Classe do veículo
 *
 * @author leofusinato
 */
class Veiculo {
    
    private $marca;
    private $modelo;
    
    function __construct($marca = null, $modelo = null) {
        $this->marca = $marca;
        $this->modelo = $modelo;
    }
    
    function getMarca() {
        return $this->marca;
    }

    function getModelo() {
        return $this->modelo;
    }

    function setMarca($marca): void {
        $this->marca = $marca;
    }

    function setModelo($modelo): void {
        $this->modelo = $modelo;
    }

}