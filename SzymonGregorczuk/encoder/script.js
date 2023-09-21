function encoder(input){
    input = btoa(input)

    return input;
}

function decoder(input){
    input = atob(input)
    return input
}
let dec = document.querySelectorAll("input[value=decode]")
let enc = document.querySelectorAll("input[value=encode]")
let text2 = document.getElementById("text2")
let text1 = document.getElementById("text1")

function popupshow(){
    document.getElementById("toast-success").style.display = 'flex'
    setTimeout(popuphide, 3000)
 
}

function popuphide(){
    document.getElementById("toast-success").style.display = 'none'
}

for (const d of dec) {
    d.addEventListener("click", function(){
        text1.value=decoder(text2.value)
        navigator.clipboard.writeText(text1.value)
        popupshow()
        
    })
}
for (const e of enc) {
    e.addEventListener("click", function(){
        text2.value=encoder(text1.value)
        navigator.clipboard.writeText(text2.value)
        popupshow()
    })
}
