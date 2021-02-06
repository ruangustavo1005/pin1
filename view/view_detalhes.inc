<?php

use Estrutura\Componentes\VeiculoMiniatura;

/**
 * View de Detalhes do Veículo
 *
 * @author Leonardo Alex Fusinato
 */
class ViewDetalhes {
    
    public function __construct() {
        ?>
        <div class="main">
            <section class="vehicle-area-images">
                <div class="vehicle-image">
                    <img src="../images/monki-flip.jpg">
                </div>
                <?php
                    new VeiculoMiniatura();
                    new VeiculoMiniatura();
                    new VeiculoMiniatura();
                    new VeiculoMiniatura();
                    new VeiculoMiniatura();
                ?>
            </section>
            <section class="vehicle-info-area">
                <h2>Informações do Veículo</h2>
            </section>
        </div>
        <?php
    }
    
}