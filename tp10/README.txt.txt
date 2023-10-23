TP10 - Semáforo por Demanda

Crear el diagrama de estados de un semáforo por demanda y luego programarlo para que funcion en
las distintas placas de la materia.
El semáforo por demanda permite que los autos estén pasando todo el tiempo (el semáforo siempre
está en verde) hasta que el peatón presione un botón, que activa la secuencia del semáforo por un
cierto tiempo permitiendo que éste cruce y luego vuelve a verde.
En caso de que un peatón llegue con el semáforo ya en rojo y presiones el botón deberá reiniciarse el
tiempo de cruce.
En el caso de un accidente, habrá un botón de emergencias que, al ser apretado, activará una alarma
sonora, enviará un mensaje a las autoridades por puerto serie y detendrá el funcionamiendo del
semáforo (éste quedará en rojo). Al llegar las autoridades desactivarán el estado de alarma volviendo
a presionar el botón. Importante: el botón correspondiente al estado de alarma deberá ser tratado
como una interrupción externa.
El tiempo de espera entre las secuencias del semáforo es de 2 segundos, salvo el momento del cruce
del peatón que es de 5 segundos.
Recordar que los semáforos tienen un momento donde pasan por rojo y amarillo al mismo tiempo.
Cosas que se evaluarán
Prolijidad en el código (indentación adecuada), que sea de facil lectura.
Coherencia en el nombre de variables, defines y funciones.
Que sea compatible con todas las placas, el mismo código debe funcionar en las distintas placas
sin hacer cambios importantes.