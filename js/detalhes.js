let time              = 1000,
    currentImageIndex = 0;

function nextImage() {
    var images = document.getElementsByClassName("img_slide"),
        max    = images.length;
    
    images[currentImageIndex].classList.remove("selected");

    currentImageIndex++;

    if (currentImageIndex >= max) {
        currentImageIndex = 0;
    }

    images[currentImageIndex].classList.add("selected");
}

function prevImage() {
    var images = document.getElementsByClassName("img_slide"),
        max    = images.length;
    images[currentImageIndex].classList.remove("selected");
    currentImageIndex--;
    if (currentImageIndex < 0) {
        currentImageIndex = max - 1;
    }
    images[currentImageIndex].classList.add("selected");
}

function selectHorario(oHorario) {
    var oTd      = document.getElementById(oHorario.id),
       oSelected = document.querySelector('.selected-image');
    if(oTd.innerText === 'Disponível' ) {
        if(oSelected) {
            oSelected.classList.remove('selected-image');
            oSelected.classList.add('selecionavel');
        }
        oTd.removeAttribute('class');
        oTd.classList.add('selected-image');
    }
    
}

function realizaAgendamento() { 
    var oSelected = document.querySelector('.selected-image'),
        sPlaca    = document.querySelector('#placa').innerText,
        oNome     = document.getElementById('nome'),
        oCpf      = document.getElementById('cpf'),
        oData     = document.getElementById('nascimento'),
        oEmail    = document.getElementById('email'),
        oTelefone = document.getElementById('telefone');

    if (oSelected && sPlaca) {
        $.ajax({
            type: 'POST',
            url: 'http://localhost/pin1/estrutura/ajax.php',
            data: {
                controller: 'ControllerAgendamento',
                processo  : 'realizaAgendamento',
                placa     : sPlaca,
                horario   : oSelected.id,
                nome      : oNome.value,
                cpf       : oCpf.value,
                nascimento: oData.value,
                email     : oEmail.value,
                telefone  : oTelefone.value
            },
            cache   : false,
            dataType: 'html',
            success: function (oRes) {
                if (oRes) {
                    $('.bg-modal').append(oRes);
                    if(oRes.search('success') !== -1) {
                        oSelected.setAttribute('class', 'n-selecionavel');
                        oSelected.innerHTML = 'Cheio';
                    }
                    setTimeout(function() {
                        $('.container-msg-success').remove();
                        $('.container-msg-fail').remove();
                    }, 2000);
                }
            }
        });
    }
}