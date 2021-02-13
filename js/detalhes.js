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

//window.addEventListener("load", start)