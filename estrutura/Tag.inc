<?
namespace Estrutura;

/**
 * Classe para criação de tags no HTML
 * @author Ruan
 */
class Tag implements Componente {
    
    /**
     * @var string
     */
    private $nome;
    /**
     * @var array
     */
    private $atributos;
    /**
     * @var Componente
     */
    private $componentes;
    /**
     * @var string
     */
    private $conteudo;
    
    /**
     * @param string $sNome
     * @param string $sConteudo Se difinido este conteúdo, o getHtml() não vai considerar os componentes filhos.
     */
    public function __construct($sNome, $sConteudo) {
        $this->setNome($sNome)
             ->setComponentes([])
             ->setAtributos([])
             ->setConteudo($sConteudo);
    }
    
    /**
     * {@inheritdoc}
     */
    public function getNome(): string {
        return $this->nome;
    }
    
    /**
     * {@inheritdoc}
     */
    public function setNome($sNome): this {
        $this->nome = $sNome;
        return $this;
    }
    
    /**
     * {@inheritdoc}
     */
    public function getComponentes(): array {
        return $this->componentes;
    }
    
    /**
     * {@inheritdoc}
     */
    public function setComponentes(Componente $aComponentes): this {
        $this->componentes = $aComponentes;
        return $this;
    }
    
    /**
     * Retorna os atributos da tag
     * @return array
     */
    public function getAtributos(): array {
        return $this->atributos;
    }

    /**
     * Define os atributos da tag ([nome => valor, nome => valor])
     * @return $this
     */
    public function setAtributos(array $atributos): this {
        $this->atributos = $atributos;
        return $this;
    }
    
    /**
     * Retorna o conteúdo da tag
     * @return string
     */
    public function getConteudo(): string {
        return $this->conteudo;
    }

    /**
     * Define o conteúdo da tag
     * Se definido o conteúdo da tag, ela não deve possuir tag intertas (e as mesmas não serão retornadas no getHtml())
     * @return $this
     */
    public function setConteudo(string $conteudo): this {
        $this->conteudo = $conteudo;
        return $this;
    }
    
    /**
     * Adiciona um atributo à tag
     * @param string $sNome  Nome do atributo
     * @param string $sValor Valor do atributo
     * @return $this
     */
    public function addAtributo($sNome, $sValor): this {
        $this->atributos[$sNome] = $sValor;
        return $this;
    }
    
    /**
     * Remove um atributo da tag
     * @param string $sNome  Nome do atributo
     * @return $this
     */
    public function removeAtributo($sNome): this {
        if (array_key_exists($sNome, $this->getAtributos())) {
            unset($this->atributos[$sNome]);
        }
        return $this;
    }
    
    /**
     * {@inheritdoc}
     */
    public function addComponente(Componente $oComponente): this {
        $this->componentes[$oComponente->getNome()] = $oComponente;
        return $this;
    }

    /**
     * {@inheritdoc}
     */
    public function getComponente($sNome): Componente {
        return array_key_exists($sNome, $this->getComponentes()) ? $this->getComponentes()[$sNome] : null;
    }

    /**
     * {@inheritdoc}
     */
    public function findComponente($sNome): Componente {
        if (!$oComponente = $this->getComponente($sNome)) {
            foreach ($this->getComponentes() as $oComponenteFilho) {
                $oComponente = $oComponenteFilho->findComponente($sNome);
            }
        }
        return $oComponente;
    }

    /**
     * {@inheritdoc}
     */
    public function removeComponente($sNome): Componente {
        $oComponente = $this->getComponente($sNome);
        unset($this->componentes[$sNome]);
        return $oComponente;
    }
    
    /**
     * {@inheritdoc}
     */
    public function getHtml($bComFilhos = true): string {
        $sHtml = "<{$this->getNome()} {$this->getAtributosHtml()}>";
        if ($this->getConteudo() != null) {
            $sHtml .= $this->getConteudo();
        }
        else if ($bComFilhos) {
            foreach ($this->getComponentes() as $oComponente) {
                $sHtml .= $oComponente->getHtml(true);
            }
        }
        $sHtml .= "</{$this->getNome()}>";
        return $sHtml;
    }
    
    /**
     * Retorna os atributos em formato de string, para ser utilizado na criação do HTML
     * @return string
     */
    protected function getAtributosHtml(): string {
        $aAtributosHtml = [];
        foreach ($this->getAtributos() as $sNome => $sValor) {
            $aAtributosHtml[] = $sNome.'="'.$sValor.'"';
        }
        return implode(' ', $aAtributosHtml);
    }
    
}