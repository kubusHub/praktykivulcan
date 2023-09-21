function encodedp(text) {
    if (typeof text !== 'string') {
      return 'zle';
    }
  
    return btoa(text);
  }
  

  function decodedp(encoded) {
    if (typeof encoded !== 'string') {
      return 'zle';
    }
  
    return atob(encoded);
  }
  

  const encodeguzik = document.getElementById('encodeprz');
  const decodeguzik = document.getElementById('decodeprz');
  const inputText = document.getElementById('wpi');
  const outputText = document.getElementById('wyn');

  encodeguzik.addEventListener('click', function () {
      const text = inputText.value;
      const encoded = encodedp(text);
      outputText.value = encoded;
      navigator.clipboard.writeText(outputText.value);
      alert("skopiowano")
  });

  decodeguzik.addEventListener('click', function () {
      const encoded = outputText.value;
      const decoded = decodedp(encoded);
      outputText.value = decoded;
      navigator.clipboard.writeText(inputText.value);
  });