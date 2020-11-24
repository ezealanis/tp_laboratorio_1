int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);
int controller_addEmployee(LinkedList* pArrayListEmployee);
int controller_editEmployee(LinkedList* pArrayListEmployee);
int controller_removeEmployee(LinkedList* pArrayListEmployee);
int controller_ListEmployee(LinkedList* pArrayListEmployee);
int controller_sortEmployee(LinkedList* pArrayListEmployee);
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);
int getIdFromArchive(int* id);
int updateId(int id);

int controller_moverElemento(LinkedList* pArrayListEmployee);
int controller_crearCopia(char* path, LinkedList* pArrayListEmployee, LinkedList* pArrayListaCopia);
int controller_filtrar(LinkedList* pArrayListEmployee);
