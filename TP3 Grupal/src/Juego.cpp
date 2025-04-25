#include "Juego.hpp"

const char OPCION_JUEGO_1 = '1';
const char OPCION_JUEGO_2 = '2';
const char OPCION_JUEGO_3 = '3';
const char OPCION_JUEGO_4 = '4';
const char OPCION_JUEGO_5 = '5';
const char OPCION_JUEGO_6 = '6';

Juego::Juego(){
    boveda.almacenar_cristal(COMUN);
    boveda.almacenar_cristal(COMUN);
    boveda.almacenar_cristal(RARO);
    boveda.almacenar_cristal(RARO);
    boveda.almacenar_cristal(EPICO);
    boveda.almacenar_cristal(EPICO);
    boveda.almacenar_cristal(LEGENDARIO);
}

void Juego::cambiar_personaje() {
    personaje = !personaje;
    if (personaje) {
        std::cout << "Personaje principal cambiado a Optimus Prime" << std::endl;
    } else {
        std::cout << "Personaje principal cambiado a Megatron" << std::endl;
    }
}

void Juego::procesar_menu_principal() {
    menu.imprimir_titulo();
    GestorBoveda gestor_boveda(menu, boveda);
    std::cout << "Ingresa tu nombre: ";
    std::cin >> nombre_jugador;
    char opcion;
    do {
        menu.imprimir_menu_principal();
        std::cin >> opcion;
        switch (opcion) {
            case OPCION_CAMBIAR_PERSONAJE:
                cambiar_personaje();
                std::cout << "Cambiando personaje principal..." << std::endl;
                break;
            case OPCION_ROBOTS:
                procesar_personajes();
                break;
            case OPCION_BOVEDA:
                procesar_boveda(gestor_boveda);
                break;
            case OPCION_TRANSFORMERS:
                procesar_transformers();
                break;
            case OPCION_JUGAR:
                std::cout << "Iniciando la batalla final..." << std::endl;
                if (manejo_transformer.obtener_cantidad_transformer() == 0) {
                    std::cout << "No hay transformers para iniciar la batalla!!, agregue uno y reintente" << std::endl;
                }else{
                    if(personaje){
                        batalla_final =  Batalla(personaje,optimus.poder(), manejo_transformer, nombre_jugador);
                    }
                    else{
                        batalla_final = Batalla(personaje,megatron.poder(), manejo_transformer, nombre_jugador);
                    }
                    camino_minimo = batalla_final.proxima_jugada();
                    std::cout << "Cargando transformers..." << std::endl;
                    iniciar_ventana_grafica(personaje, camino_minimo);
                    batalla_final.Pelea(camino_minimo.camino,optimus,megatron);
                    tabla_clasificaciones = batalla_final.get_tabla();
                }
                break;
            case OPCION_CLASIFICACION:
                try{
                    std::cout << "Mostrando la tabla de clasificacion..." << std::endl;
                    tabla_clasificaciones.mostrar_contenido();
                }catch(...){
                    std::cout << "La tabla de clasificacion esta vacia, no hubo combates previos." << std::endl;
                }
                break;
            case OPCION_CERRAR:
                std::cout << "Gracias por jugar! Hasta la proxima" << std::endl;
                break;
            default:
                std::cout << ERROR_VALIDACION;
        }
    } while (opcion != OPCION_CERRAR);
}

void Juego::procesar_personajes() {
    char opcion;
    if (personaje){
        do {
            menu.imprimir_menu_optimus();
            std::cin >> opcion;
            std::cin.ignore();
            switch (opcion) {
            case '1': {
                optimus.Opcion_1();
                break;
            }
            case '2': {
                std::string mensaje;
                std::cout << std::endl << FONDO_ROJO <<"-1 para dejar de mandar mensajes" << COLOR_POR_DEFECTO << std::endl << std::endl;
                do {
                    mensaje = menu.pedir_mensaje();
                    if (mensaje != "-1") {
                        std::cout << RESALTADO_AZUL;
                        optimus.responder(mensaje);
                        std::cout << COLOR_POR_DEFECTO << std::endl;
                    }
                } while (mensaje != "-1");
                break;
            }
            case '3': {
                std::cout << RESALTADO_AZUL;
                optimus.sugerir_fusion();
                std::cout << COLOR_POR_DEFECTO;
                break;
            }
            case OPCION_CERRAR: {
                std::cout << VOLVER_MENU_PRINCIPAL << std::endl;
                break;
            }
            default: {
                std::cout << ERROR_VALIDACION << std::endl;
            }
            }
        } while (opcion != OPCION_CERRAR);
    } else {
        do {
            menu.imprimir_menu_megatron();
            std::cin >> opcion;
            std::cin.ignore();
            switch (opcion) {
            case '1': {
                megatron.Opcion_1();
                break;
            }
            case '2': {
                std::string mensaje;
                std::cout << std::endl << FONDO_ROJO << "-1 para dejar de mandar mensajes" << COLOR_POR_DEFECTO << std::endl << std::endl;
                do {
                    mensaje = menu.pedir_mensaje();
                    if (mensaje != "-1") {
                        std::cout << RESALTADO_GRIS;
                        megatron.responder(mensaje);
                        std::cout << COLOR_POR_DEFECTO << std::endl;
                    }
                } while (mensaje != "-1");
                break;
            }
            case '3': {
                std::cout << RESALTADO_GRIS;
                megatron.sugerir_fusion();
                std::cout << COLOR_POR_DEFECTO;
                break;
            }
            case OPCION_CERRAR: {
                std::cout << VOLVER_MENU_PRINCIPAL << std::endl;
                break;
            }
            default: {
                std::cout << ERROR_VALIDACION << std::endl;
            }
            }
        } while (opcion != OPCION_CERRAR);
    }
}

void Juego::procesar_boveda(GestorBoveda& gestor_boveda) {
    char opcion;
    do {
        menu.imprimir_menu_boveda();
        std::cin >> opcion;
        switch (opcion) {
            case '1':
                gestor_boveda.almacenar_cristal();
                break;
            case '2':
                gestor_boveda.mostrar_cristales();
                break;
            case '3':
                gestor_boveda.exportar_cristales();
                break;
            case '4':
                gestor_boveda.fusionar_cristales();
                break;
            case '5':
                gestor_boveda.mostrar_cristal_mas_poderoso(personaje, optimus, megatron); 
                break;
            case '6':
                gestor_boveda.equipar_cristal(personaje, optimus, megatron);
                break;
                break;
            case OPCION_CERRAR:
                std::cout << VOLVER_MENU_PRINCIPAL << std::endl;
                break;
            default:
                std::cout << ERROR_VALIDACION << std::endl;
        }
    } while (opcion != OPCION_CERRAR);
}

void Juego::procesar_transformers() {
    char opcion;
    do {
        menu.imprimir_menu_transformers();
        std::cin >> opcion;
        switch (opcion) {
            case '1': {
                if (manejo_transformer.obtener_cantidad_transformer() < 18){
                    std::string nombre;
                    size_t fuerza, defensa, velocidad, faccion, vehiculo;
                    bool transformado;
                    std::cout << "Ingrese el nombre del Transformer: ";
                    std::cin >> nombre;
                    std::cout << "Ingrese la fuerza del Transformer: ";
                    std::cin >> fuerza;
                    std::cout << "Ingrese la defensa del Transformer: ";
                    std::cin >> defensa;
                    std::cout << "Ingrese la velocidad del Transformer: ";
                    std::cin >> velocidad;
                    std::cout << "Ingrese la faccion del Transformer (1 = Autobots, 2 = Decepticons): ";
                    std::cin >> faccion;
                    if (faccion == 1) {
                        std::cout << "Ingrese el vehiculo del Transformer (1 = Auto, 2 = Camion): ";
                        std::cin >> vehiculo;
                    } else {
                        std::cout << "Ingrese el vehiculo del Transformer (1 = Tanque, 2 = Avion): ";
                        std::cin >> vehiculo;
                    }
                    std::cout << "Ingrese si el Transformer esta transformado (1 = Si, 0 = No): ";
                    std::cin >> transformado;
                    try{
                    if (faccion == 1) {
                        manejo_transformer.alta_transformer(nombre, fuerza, defensa, velocidad, faccion, vehiculo, transformado);
                    } else {
                        manejo_transformer.alta_transformer(nombre, fuerza, defensa, velocidad, faccion, vehiculo + 2, transformado);
                    }
                    std::cout << "Transformer agregado correctamente" << std::endl;
                    }catch(...){
                        std::cout << "No se puedo agregar Transformers, valores incorrectos." << std::endl;
                    }
                } else{
                    std::cout << "No se pueden agregar mas transformers, ya hay suficientes para la batalla." << std::endl;
                }
                break;
            }
            case '2':{
                manejo_transformer.mostrar_listado_transformers();
                Vector<Transformer*> listado = manejo_transformer.obtener_transformers();
                for (size_t i = 0; i < listado.tamanio(); i++) {
                    std::cout << "Nombre: " << listado[i]->obtener_nombre() << std::endl;
                }
                break;
            }
            case '3': {
                std::string nombre;
                std::cout << "Ingrese el nombre del transformer a buscar: ";
                std::cin >> nombre;
                try
                {
                    manejo_transformer.busqueda_transformer(nombre);
                    std::cout << "El Transformer se encuentra en el listado" << std::endl;
                }
                catch(...)
                {
                    std::cout << "Transformer no encontrado" << std::endl;
                }
                
                break;
            }
            case '4': {
                std::string nombre;
                std::cout << "Ingrese el nombre del Transformer a eliminar: ";
                std::cin >> nombre;
                try
                {
                    manejo_transformer.baja_transformer(nombre);
                    std::cout << "Transformer eliminado" << std::endl;
                }
                catch(...)
                {
                    std::cout << "El transformer no existe!" << std::endl;
                }
                break;
            }
            case '5':{
                std::string nombre;
                std::cout << "Ingrese el nombre del Transformer a transformar: ";
                std::cin >> nombre;
                try
                {
                    Transformer* transformer = manejo_transformer.busqueda_transformer(nombre);
                    manejo_transformer.transformar_transformer(transformer);
                    std::cout << "Transformer transformado" << std::endl;
                }
                catch(...)
                {
                    std::cout << "El transformer no existe!" << std::endl;
                }
                break;
            }
            case OPCION_CERRAR:
                std::cout << VOLVER_MENU_PRINCIPAL << std::endl;
                break;
            default:
                std::cout << ERROR_VALIDACION << std::endl;
        }       
    } while (opcion != OPCION_CERRAR);
}

void Juego::iniciar_ventana_grafica(bool personaje, Camino camino_min){
    MapaGrafo mapa(personaje, camino_minimo);
    mapa.iniciar_ventana();
    return;
}