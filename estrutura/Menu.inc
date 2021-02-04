<?php

namespace Estrutura;

/**
 * Classe do Menu
 *
 * @author Leonardo Alex Fusinato
 */
class Menu {

    public function __construct() {
        ?>
        <div class='logo'>
            <a href="#"><img src="../images/logo.png" alt="Fusuan Motors"></a>
            <span>Fusuan Motors</span>
        </div>
        <nav>
            <ul>
                <li><a href="estoque.php">Estoque</a></li>
                <li><a href="contato.php">Contato</a></li>
            </ul>
        </nav>
        <?php
    }

}
