<?php

/**
 * Classe do veículo
 *
 * @author Leonardo Alex Fusinato
 */
class Veiculo {
    
    private $marca;
    private $modelo;
    private $ano;
    
    function __construct($marca = null, $modelo = null, $ano = null) {
        $this->marca  = $marca;
        $this->modelo = $modelo;
        $this->ano    = $ano;
    }
    
    public function getMarca() {
        return $this->marca;
    }

    public function getModelo() {
        return $this->modelo;
    }

    public function getAno() {
        return $this->ano;
    }

    public function setMarca($marca): void {
        $this->marca = $marca;
    }

    public function setModelo($modelo): void {
        $this->modelo = $modelo;
    }

    public function setAno($ano): void {
        $this->ano = $ano;
    }


}