If you plan to make changes, use this command to check out the code as yourself using HTTPS:
# Project members authenticate over HTTPS to allow committing changes.
svn checkout https://kruskal.googlecode.com/svn/trunk/ kruskal --username (tu\_user)

svn update /**para bajar los archivos**/

svn commit -m "comentario" /**para subir archivos**/

svn add "archivo" /**agregar un archvio que no este en el hosting y despues un svn commit para q modifique**/