export function calcularMensalidade(
    valor: number,
    desconto: number
): number{
    return valor*(100-desconto)/100;
}

