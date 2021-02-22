<?php

namespace Estrutura\Componentes;

/**
 * Classe para a Criação de Cards de Veículos
 *
 * @author Leonardo Alex Fusinato
 */
class CardVeiculo {
    
    private $Veiculo;

    public function __construct(\Veiculo $oVeiculo) {
        $this->Veiculo = $oVeiculo;
    }
    
    public function getHtml() {
        $sHtml = '<div class="card-veiculo">
                <div class="image-area">';
        if(sizeof($this->Veiculo->getImagens()) > 0) {
            $sHtml .=  "<img class=\"vehicle-image\" src=\"data:image/jpeg;base64, {$this->Veiculo->getImagens()[0]->getConteudo()}\"/>";
        }
        $sHtml .='        
            </div>
                <div class="info">
                    <span> '.$this->Veiculo->getModelo()->getMarca()->getNome() . ' ' . $this->Veiculo->getModelo()->getNome() . ' ' . $this->Veiculo->getAnoFabricacao() .'</span><br>
                    <span> R$ '.$this->Veiculo->getPreco().' </span>
                </div>
                <button class="btn-detalhes open-modal" id="'.$this->Veiculo->getPlaca().'" onclick="abrirDetalhes('.$this->Veiculo->getPlaca().')">Agendar Visita</button> 
            </div>';
        return $sHtml;
    }

}