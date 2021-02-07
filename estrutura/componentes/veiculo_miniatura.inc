<?php

namespace Estrutura\Componentes;

/**
 * Classe para a Criação de Imagens Pequenas do Veículo
 *
 * @author Leonardo Alex Fusinato
 */
class VeiculoMiniatura {
    
    
    public function __construct() {
        ?>
        <div class="small-image">
            <img src="../images/hb20.jpg" onclick="alterImage()">
        </div>
        <?php
    }
    
}
?>
<script type="text/javascript" src="../js/veiculo_miniatura.js"></script>