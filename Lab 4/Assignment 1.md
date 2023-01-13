# Assignment 1

a) Nach einer ISR oder wenn der aktuell ausgeführte Task in den Zustand 'waiting' übergeht
(z.B. beim warten auf ressourcen o.ä.)

b)
- OSxxxPend blockiert bis die Ressource verfügbar ist oder ein optionales Timeout abgelaufen ist
- OSxxxAccept kann nicht blockieren und kehrt auf jeden Fall zum aufrufenden Task zurück
