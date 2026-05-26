# codexion

_Este proyecto ha sido creado como parte del currículo de 42 por <jpedra-v>_

__Descripción__
En este proyecto creamos una simulación en la cual:

• Tenemos programadores en un una mesa circular. En el centro, hay un Compilador Cuántico compartido.
• Las personas alternan entre compilar, depurar o refactorizar.
• Hay dongles USB en la mesa. Tantos dongles como personas que programan.
• Compilar código cuántico requiere dos dongles conectados simultáneamente.
• Cuando una persona termina de compilar, devuelve ambos dongles a la mesa y comienza a depurar.
• Una vez terminada la depuración, comienza a refactorizar. 
• La simulación se detiene cuando alguien se agota o todos han cumplido una cuota establecida.
• Todas las personas necesitan compilar regularmente para no agotarse.

__Instrucciones__

### Compilar:
``` bash
make
```

### Ejecutar:
_Manual_
``` bash
./codexion <number_of_coders> <time_to_burnout> <time_to_compile> <time_to_debug> <time_to_refactor> <number_of_compiles_required> <dongle_cooldown> <scheduler>
```
_Ejemplo_
``` bash
./codexion 4 500 200 200 100 5 100 fifo
```

### Scheduler:
_FIFO_
"First In, First Out" el dongle se concede a la persona cuya solicitud llegó primero.

_EDF_
"Earliest Deadline First" el dongle se concede a la persona más cercana al agotamiento.

__Casos de bloqueo manejados__

1. Prevención de Interbloqueos (Deadlocks)

	Cada programador intenta coger siempre primero el dongle con el identificador numérico más
	bajo de los dos que tiene asignados. Esto rompe el ciclo de espera en la mesa circular, 
	garantizando que al menos un programador siempre pueda obtener ambos dongles y compilar.

2. Prevención de Inanición (Starvation)
	
	**En FIFO:** Se garantiza la equidad mediante una cola de solicitudes. 
	Ningún programador se queda esperando indefinidamente si llegó antes.
	
	**En EDF:** El planificador prioriza activamente a los hilos cuyo `time_to_burnout` 
	está más cerca de expirar. Los hilos "saludables" ceden el paso a los que están a punto 
	de agotarse.

3. Gestión del Cooldown de los Dongles

	Cuando un dongle se libera, entra en un estado de *cooldown*. Durante este tiempo, 
	un temporizador impide que cualquier hilo (incluido el que lo acaba de soltar) 
	lo vuelva a reclamar.

4. Detección Precisa del Agotamiento (Burnout)

	El tiempo corre en milisegundos reales. Para evitar falsos positivos o muertes tardías,
	un hilo monitor independiente evalúa constantemente la salud de los programadores sin 
	bloquear el progreso de la simulación.
		...

5. Serialización del Log (Data Races en Output)
	
	Si varios hilos intentan escribir en `stdout` a la vez, los mensajes se mezclarían 
	rompiendo el formato. Se utiliza un mutex global exclusivo para la escritura de logs,
	asegurando que cada línea sea un mensaje atómico y cronológico. Además, el log se 
	detiene inmediatamente el mismo milisegundo en que alguien se agota.

__Mecanismos de sincronización de hilos.__

1. pthread_mutex_t:
	
	Bloqueo de recursos: Cada dongle tiene un mutex dedicado. 
	Este actúa como un bloqueo físico; un programador debe adquirir los mutexes de 
	ambas llaves que le han sido asignadas para comenzar a compilar.
	
	Prevención de conflictos de datos: Las variables compartidas como simulation_active,
	time_to_burnout y have_finished están protegidas por mutexes individuales. 
	Cuando el monitor lee el estado de un codificador, bloquea mutex_burnout el tiempo justo
	necesario para copiar el valor, evitando así un conflicto de datos si el codificador 
	actualiza su marca de tiempo simultáneamente.

2. pthread_cond_t:
	
	Se utiliza para evitar la "espera activa" Cuando se añade un programador y este 
	tiene que esperar, llama a pthread_cond_wait. Esto pone el hilo en suspensión 
	(0 % de uso de la CPU).

	Cuando un programador termina de compilar y libera sus dongles, activa
	pthread_cond_broadcast. Esto envía una señal de activación a todos los 
	programadores en espera, lo que permite reevaluar su prioridad e intentar
	adquirir los dongles de nuevo.

__Recursos__

- Proyectos similares en GitHub fueron usados como punto de referencia para varios conceptos.

- La IA fue usada para ayudarme con problemas básicos pero tediosos con la Norminette 
  (ej., `line too long`).
 
- La IA fue usada para discutir cuál se consideraría la opción más eficiente al tener múltiples 
  formas de solucionar X problema.
  
- La IA fue usada para aplicar los acentos en el README.
