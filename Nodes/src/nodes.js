var nodes = [];
var count = 0;

function createNode( _name )
{
	var text;
	var type;
	var op;
	switch(_name)
	{
		case "Sphere": 
		{
			text = SphereNode();
			type = "primitive"; 
			op = "Sphere("
			break;
		}

		case "Cube": 
		{
			text = CubeNode();
			type = "primitive";
			break;
		}

		case "Union":
		{
			text = UnionNode();
			type = "operation"; 
			break;
		}
		default: break;
	}

	var editor = document.getElementById('editor');
    editor.innerHTML += text;
    var node = new Node();
    node.name = _name +"_"+ count;
	node.id = count;
	node.type = type;
    nodes.push( node );
	++count;
}


class Node
{
    constructor()
    {
        this.name;
		this.id;
        this.next;
		this.type;
        this.x;
        this.y;
    }
}

function SphereNode()
{
	var node = '<div name = "Sphere_'+ count +'" id ="'+ count +'" class="draggable node">';
	node += '<h3>Sphere</h3>';
  	node += '<label> X:</label> <input type="text" name="0" maxlength="4" size="4">';
  	node += '<label> Y:</label> <input type="text" name="1" maxlength="4" size="4">';
	node += '<label> Z:</label> <input type="text" name="2" maxlength="4" size="4"><br/>';
	node += '<label> R:</label> <input type="text" name="3" maxlength="4" size="4">';
	node += '</div>';
	return node;
}

function CubeNode()
{
	var node = '<div name = "Cube_'+ count +'" id ="'+ count +'" class="draggable node">';
	node += '<h3>Cube</h3>';
  	node += '<label> X:</label> <input type="text" name="0" maxlength="4" size="4">';
  	node += '<label> Y:</label> <input type="text" name="1" maxlength="4" size="4">';
	node += '<label> Z:</label> <input type="text" name="2" maxlength="4" size="4"><br/>';
	node += '<label> S:</label> <input type="text" name="3" maxlength="4" size="4">';
	node += '</div>';
	return node;
}

function UnionNode()
{
	var node = '<div name = "Union_'+ count +'" id ="'+ count +'" class="draggable node">';
	node += '<h3>Union</h3>';
	node += '</div>';
	return node;
}

function Evaluate()
{
	var connections = [];
	for( var i = 0; i < jsPlumb.getConnections().length; ++ i )
	{
		var src = jsPlumb.getConnections()[i].source.attributes.name.nodeValue;
		var dst = jsPlumb.getConnections()[i].target.attributes.name.nodeValue;
		var isIn = false;
		for ( var j = 0; j < connections.length; ++ j )
		{
			if (dst == connections[j][0])
			{
				isIn = true;
				connections[j].push(src)
			}
		}
		if( !isIn )
			connections.push( [dst, src] );	
	}
	console.log(connections);

}

jsPlumb.ready( function() 
{

	
});

$(document).ready(function()
{
	$(document).keydown(function(e)
	{
		if ( e.key === "w" )
		{
			Evaluate();
		}

		if ( e.key === "s" )
		{
			createNode("Sphere");
		}

		if ( e.key === "c" )
		{
			createNode("Cube");
		}
		
		if ( e.key === "u" )
		{
			createNode("Union");
		}
		for (var i = 0; i < nodes.length; ++i)
	{
		var name = nodes[i].name.split("_")[0];
		if ( nodes[i].type == "primitive" )
		{
			jsPlumb.addEndpoint( i.toString(), { anchors:["Right"], connector: ["Bezier"], isSource:true, maxConnections: 100});
			jsPlumb.draggable(i.toString());
		}
		else if ( nodes[i].type == "operation" )
		{
			jsPlumb.draggable(i.toString());
			jsPlumb.addEndpoint(i.toString(), { anchors:["Left"], connector: ["Bezier"], isTarget:true, maxConnections: 100 });
			jsPlumb.addEndpoint(i.toString(), { anchors:["Right"], connector: ["Bezier"], isSource:true, maxConnections: 100 });
		}
	}
	});
});
