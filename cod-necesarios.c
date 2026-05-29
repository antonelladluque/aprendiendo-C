void buscarClientePorDNI(struct Cliente clientes[], int cantidad) {
    
        ordenarClientes(clientes, cantidad);

    int buscar;
    int inicio = 0;
    int fin = cantidad - 1;
    int mitad;
    int encontrado = 0; (0 = no, 1 = si)

    
    printf("\nIngrese el numero de DNI del cliente a buscar: ");
    scanf("%d", &buscar);

        while (inicio <= fin && encontrado == 0) {
        mitad = (inicio + fin) / 2;
        
        if (clientes[mitad].dni == buscar) {
            encontrado = 1; 
        } 
        else if (clientes[mitad].dni < buscar) {
            inicio = mitad + 1; 
        } 
        else {
            fin = mitad - 1;   
        }
    }
    
       if (encontrado == 1) {
        printf("\n[RESULTADO] Cliente Encontrado exitosamente.\n");
        printf("DNI: %d - Nombre: %s %s - Saldo: %.2f\n", 
               clientes[mitad].dni, 
               clientes[mitad].nombre, 
               clientes[mitad].apellido, 
               clientes[mitad].saldo);
    } else {
        printf("\n[RESULTADO] El cliente con DNI %d no existe en el sistema.\n", buscar);
    }
}

	//-------------------------------

void listarPiezasActivas(struct Pieza piezas[], int cantidad){
	 printf("-- PIEZAS ACTIVAS -- \n\n");
	 

	for (int i=0 , i < cantidad ; i++) {
		if (piezas[i].activa == 1) { 
		 	printf("Pieza de la posicion %d  (%d,%d) esta activa\n", 
                   piezas[i].posicion[0], piezas[i].posicion[1]);
}
}
}

//------------------------------------

void listarClientesPorSaldo(struct Cliente clientes[], int cantidad){
 //ordenar por saldo
	struct Cliente aux_saldo;
  for (int i = 0; i < cantidad - 1; i++){
    for (int j = 0; j < cantidad - i - 1; j++){
      if (clientes[j].saldo > clientes[j + 1].saldo) {
        aux_saldo = clientes[j];
        clientes[j] = clientes[j + 1];
        clientes[j + 1] = aux_saldo;
      }
    }
  }

	printf("\n--- CLIENTES POR SALDO ---\n");
    for(i = 0; i < cantidad; i++) {
        printf("\nCliente Nro: %d - Saldo: %.2f", clientes_[i].nro_cliente, clientes_[i].saldo);
    }
}

//---------------------------------
void listarPiezasPorPosicion(struct Pieza piezas[], int cantidad){
	//Ordenar primero llamando a la funcion que ya existe
    ordenarPiezas(piezas, cantidad);

	printf("\n--- LISTA DE PIEZAS POR POSICION ---\n");	
	for (int i = 0; i < cantidad; i++){
        	printf("Pieza %d - Posicion: (%d,%d),piezas[i].posicion[0], piezas[i].posicion[1]);
}}
//-----------------------------------------
