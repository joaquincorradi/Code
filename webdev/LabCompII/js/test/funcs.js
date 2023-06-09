function sumar() {
  var num1 = document.getElementById("n1").value;
  var num2 = document.getElementById("n2").value;
  num1 = parseInt(num1);
  num2 = parseInt(num2);
  var resultado = num1 + num2;
  if (isNaN(num1) || isNaN(num2)) {
    alert("Ingrese una opcion correcta");
  } else {
    document.getElementById("respuesta").innerHTML =
      "El resultado es " + resultado;
  }
}
