<?php

/**
 * Modelo do Horário do Agendamento
 *
 * @author Leonardo Alex Fusinato
 */
class HorarioAgendamento {
 
    private $dia;
    private $hora1;
    private $hora2;
    private $hora3;
    private $hora4;
    private $hora5;
    private $hora6;
    private $hora7;
    private $hora8;
    private $hora9;
    
    public function getDia() {
        return $this->dia;
    }

    public function getHora1() {
        return $this->hora1;
    }

    public function getHora2() {
        return $this->hora2;
    }

    public function getHora3() {
        return $this->hora3;
    }

    public function getHora4() {
        return $this->hora4;
    }

    public function getHora5() {
        return $this->hora5;
    }

    public function getHora6() {
        return $this->hora6;
    }

    public function getHora7() {
        return $this->hora7;
    }

    public function getHora8() {
        return $this->hora8;
    }

    public function getHora9() {
        return $this->hora9;
    }

    public function setDia($dia): void {
        $this->dia = $dia;
    }

    public function setHora1($hora1): void {
        $this->hora1 = $hora1;
    }

    public function setHora2($hora2): void {
        $this->hora2 = $hora2;
    }

    public function setHora3($hora3): void {
        $this->hora3 = $hora3;
    }

    public function setHora4($hora4): void {
        $this->hora4 = $hora4;
    }

    public function setHora5($hora5): void {
        $this->hora5 = $hora5;
    }

    public function setHora6($hora6): void {
        $this->hora6 = $hora6;
    }

    public function setHora7($hora7): void {
        $this->hora7 = $hora7;
    }

    public function setHora8($hora8): void {
        $this->hora8 = $hora8;
    }

    public function setHora9($hora9): void {
        $this->hora9 = $hora9;
    }
    
}