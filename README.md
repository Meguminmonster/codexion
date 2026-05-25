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
Manual:
``` bash
./codexion <number_of_coders> <time_to_burnout> <time_to_compile> <time_to_debug> <time_to_refactor> <number_of_compiles_required> <dongle_cooldown> <scheduler>
```
Ejemplo:
``` bash
./codexion 4 500 200 200 100 5 100 fifo
```

__Recursos__
...

__Casos de bloqueo manejados__
...

Describa todos los problemas de concurrencia gestionados en la solución creada 
(por ejemplo, prevención de interbloqueos y condiciones de Coffman, 
prevención de inanición, gestión del cooldown, detección precisa 
del agotamiento y serialización del log)

__Mecanismos de sincronización de hilos.__
...

Explicando las primitivas de hilos específicas usadas en la implementación 
(pthread_mutex_t, pthread_cond_t, implementación personalizada de eventos) 
y cómo coordinan el acceso a recursos compartidos 
(dongles, logging, estado del monitor). 
Debe incluir ejemplos de cómo se evitan las condiciones de carrera 
y cómo se logra una comunicación thread-safe
entre las personas que programan y el monitor
