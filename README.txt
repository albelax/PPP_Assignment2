PPP Assignment

In order to run my project it is necessary to build the library GLFunctionsLib, once it's done everything should compile and build normally.

In this assignment the user will control the player, arrow keys will make the player move and the space bar will make the player shoot,
the goal is to eliminate all the enemies in the scene, which will shoot back.

many things changed from the initial design during the development process, mostly because my experience increased during that time.

I decided to generate the rooms of the map and then edit it by hand having as a result a file (map.txt) which contains 0 for the walls, 1 for the empty spaces, e for the static enemies, 2 3 and 4 for the enemies that rotate around a base.

Once I had the map I wrote a simple script to generate an image of the map, then moved to a 3d software where I made the level in 3d and divided it in chunks that would be imported later.

I used the “map.txt” file once again to calculate collision detections between the player (or any other moving objects) and the world by calculating the position of the GameObject divided by the size of each cell, this way I would find the position of the object in the map file and if in that index the value was 0 we would know a collision happened.

To import the map and other 3d objects I thought it would be interesting to write my own .obj importer, I succeed in the job but in the beginning it was slow (the first version can be found in the UtilityFunctions.cpp), so I decided to create the Mesh class, where I used a different approach that was indeed faster.
Having a Mesh as an object allowed me to share resources between objects in the scene, I used the technique of having a single mesh imported and all the object that need that specific mesh will only have a pointer to that mesh, this saved a lot of memory and it was to my opinion a much cleaner approach than letting all the objects have their own mesh.

The Level class contains almost everything, I decided to use it this way because it was easier, and made sense, to have an object that could have access to all other so that later I could have all the updates in the same timer callback and so on.

To make the player move I decided it was best to let he player have access an SDL_Event instance ( the on in the main ), and then store the inputs in an array ( 1 if the key is pressed 0 if is not),
and based on that array let the player move, this avoided some bugs that I had with the previous project (space invaders), where if the user pushed two buttons at once without releasing any key the results were a bit unexpected.
The health of the player is displayed as a sphere that changes colour from green to red, I figured this would be a nicer, and easier, approach rather than introducing a GUI.
by introducing a few changes to the Input function and to the Level class this game could be easily made a multiplayer game, unfortunately I did not try this yet because of the lack of time.