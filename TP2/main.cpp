#include "Menu.hpp"
#include "OptimusPrime.hpp"
#include "Megatron.hpp"
#include "Cristal.hpp"
#include "BovedaCristales.hpp"
#include "FusionadorEnergon.hpp"
#include "Vector.hpp"
#include "GestorBoveda.hpp"

int main() {
    OptimusPrime optimus;
    Megatron megatron;
    Menu menu;
    BovedaCristales boveda;
    GestorBoveda gestor_boveda(menu, boveda);
    Cristal cristal_comun1(COMUN);
    boveda.almacenar_cristal(cristal_comun1);
    Cristal cristal_comun2(COMUN);
    boveda.almacenar_cristal(cristal_comun2);
    Cristal cristal_raro(RARO);
    boveda.almacenar_cristal(cristal_raro);
    Cristal cristal_epico(EPICO);
    boveda.almacenar_cristal(cristal_epico);
    Cristal cristal_legendario(LEGENDARIO);
    boveda.almacenar_cristal(cristal_legendario);
    menu.imprimir_titulo();
    char opcion;
    char opcion_robots;
    char opcion_boveda;
    do {
        menu.imprimir_menu_principal();
        std::cin >> opcion;
        switch (opcion) {
            case OPCION_BOVEDA:
                do {
                    menu.imprimir_menu_boveda();
                    std::cin >> opcion_boveda;
                    switch (opcion_boveda) {
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
                            std::cout << "Volviendo al menu principal..." << std::endl;
                            break;
                        default:
                            std::cout << ERROR_VALIDACION;
                    }
                } while (opcion_boveda != '5');
                break;
            case OPCION_ROBOTS:
                do {
                    menu.imprimir_menu_robots();
                    std::cin >> opcion_robots;
                    switch (opcion_robots) {
                        case OPCION_OPTIMUS:
                            optimus.procesar(menu);
                            break;
                        case OPCION_MEGATRON:
                            megatron.procesar(menu);
                            break;
                        case '3':
                            std::cout << "Volviendo al menu principal..." << std::endl;
                            break;
                        default:
                            std::cout << ERROR_VALIDACION;
                    }
                } while (opcion_robots != '3');
                break;
            case '3':
                std::cout << "Gracias por jugar! Hasta la proxima" << std::endl;
                break;
            default:
                std::cout << ERROR_VALIDACION;
        }
    } while (opcion != '3');
    return 0;
}