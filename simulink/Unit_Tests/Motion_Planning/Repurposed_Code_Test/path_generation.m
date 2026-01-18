function pg = PathGenerator()
pg.nodes = load_field_nodes(); % must return containers.Map
pg.start = [];
pg.finish = [];
end

function node = get_nearest_node(nodes, x, y)
    keys = nodes.keys;
    minDist = inf;
    node = [];
    
    for i = 1:length(keys)
        n = nodes(keys{i});
        d = hypot(n.x - x, n.y - y);
        if d < minDist
            minDist = d;
            node = n;
        end
    end
end

function path = generate_node_path(pg)
    path = {};

    if isempty(pg.start) || isempty(pg.finish)
        return;
    end

    result = a_star(pg.start, pg.finish);
    path = result;
end

function t = translation(x, y)
t.x = x;
t.y = y;
end

function d = translation_dist(a, b)
d = hypot(b.x - a.x, b.y - a.y);
end

function ang = translation_angle(t)
ang = atan2(t.y, t.x);
if ang < 0
    ang = ang + 2*pi;
end
end

function t = translation_from_node(node)
t.x = node.x;
t.y = node.y;
end

function translations = point_to_point_path(pg, start_pos, finish_pos)
translations = {};

pg.start = get_nearest_node(pg.nodes, start_pos.x, start_pos.y);
pg.finish = get_nearest_node(pg.nodes, finish_pos.x, finish_pos.y);

if isempty(pg.start) || isempty(pg.finish)
    error("Path Generation Error: nullptr");
end

result = a_star(pg.start, pg.finish);
if isempty(result)
    error("Path Generation Error: a_star failure");
end

translations{end+1} = start_pos;
for i = 2:length(result)-1
    translations{end+1} = translation_from_node(result{i});
end
translations{end+1} = finish_pos;
end

function translations = multi_point_path(pg, positions)
translations = {};

for i = 1:length(positions)-1
    segment = point_to_point_path(pg, positions{i}, positions{i+1});
    if isempty(segment)
        translations = {};
        return;
    end
    translations = [translations, segment];
end

translations{end+1} = positions{end};
end
