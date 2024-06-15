# General project conventions
- variable name separated with `_`
- function name separated with capital letters
- private data member `m_`
- if possible initialize the hardcode value of private data member in the private decleration
- no public data member
- class usage only if necessary di base il codice deve essere procedurale che utilizza quando necessario gli oggetti. La logica di base è procedurale.
- Documentare i membri delle classi con una riga di descrizione nella dichiarazione solo se necessario
- no ineretance o object composition se non è strettamente necessario nella applicazione attuale o futura
- variabili globali iniziali con `g_`
- per private data member use `m_`
- use size_t nei for con vector
- add log library
- usare le "feature" avanzate di c++ solo in casi in cui non è necessariua l'efficienza del codice. Per ogni "feature" prima immaginarsi il codice senza di essa e poi pensare se sia davvero necessaria
- simple code
- copnstant and static private data member start with `s_` `c_`

Documentazione:
- state diagram
- activity diagram: per la parte procedurale del codice
- class diagram: per descrivere gli oggetti usati nella parte procedurale 
    nel class diagram indicare possibili futuri espnsioni di classi, ecc...
- Inserire nei diagrammi i namespace e le cartelle del codice sorgente
