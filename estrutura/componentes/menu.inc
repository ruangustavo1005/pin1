<?php

namespace Estrutura\Componentes;

/**
 * Classe do Menu
 *
 * @author Leonardo Alex Fusinato
 */
class Menu {

    public function __construct() {
        ?>
        <div class='logo'>
            <a href="estoque.php"><img src="./images/logoo.jpeg" alt="Fusuan Motors"></a>
        </div>
        <nav>
            <ul>
                <li><a href="index.php">Estoque</a></li>
                <li><a href="contato.php">Contato</a></li>
                <!--<span>SEU PRÓXIMO VEÍCULO ESTÁ AQUI!<span>-->
            </ul>
        </nav>
        <?php
    }

}
