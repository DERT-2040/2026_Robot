classdef VictiPathMATLAB
    properties
        pg % PathGenerator struct
    end
    
    methods
        function obj = VictiPathMATLAB()
            obj.pg = PathGenerator();
            if isempty(obj.pg.nodes) || obj.pg.nodes.Count == 0
                error('VictiPath Error: Could not find field nodes.');
            end
        end
        
        function setStartPoint(obj, x, y)
            obj.pg.start = get_nearest_node(obj.pg.nodes, x, y);
        end
        
        function setFinishPoint(obj, x, y)
            obj.pg.finish = get_nearest_node(obj.pg.nodes, x, y);
        end
        
        function path = generateNodePath(obj)
            pathNodes = generate_node_path(obj.pg);
            path = cellfun(@(n) translation_from_node(n), pathNodes, 'UniformOutput', false);
        end
        
        function translations = pointToPointPath(obj, start_pos, finish_pos)
            translations = point_to_point_path(obj.pg, start_pos, finish_pos);
        end
        
        function translations = multiPointPath(obj, positions)
            translations = multi_point_path(obj.pg, positions);
        end
    end
end
