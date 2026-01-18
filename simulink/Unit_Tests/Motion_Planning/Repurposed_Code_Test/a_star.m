function path = a_star(startNode, finishNode)
% A* pathfinding between startNode and finishNode

records = create_record_list();
records = add_record(records, create_record(startNode, 0, 0, []));

while records.open > 0

    % find open node with least total cost
    least = [];
    leastCost = inf;
    for i = 1:records.size
        rec = records.records{i};
        if rec.closed
            continue;
        end
        if rec.cost_total < leastCost
            leastCost = rec.cost_total;
            least = rec;
        end
    end

    % explore successors
    for i = 1:length(least.node.successors)
        successor = least.node.successors{i};

        successor_record = create_record( ...
            successor, ...
            least.cost_start + distance(least.node, successor), ...
            distance(successor, finishNode), ...
            least ...
        );

        % reached goal
        if successor == finishNode
            path = {};
            ptr = successor_record;
            while ~isempty(ptr.parent)
                path = [{ptr.node}, path];
                ptr = ptr.parent;
            end
            path = [{ptr.node}, path];
            return;
        end

        skip = false;
        for j = 1:records.size
            rec = records.records{j};
            if rec.node == successor && rec.cost_total <= successor_record.cost_total
                skip = true;
                break;
            end
        end

        if ~skip
            records = add_record(records, successor_record);
        end
    end

    records = close_record(records, least);
end

path = {}; % failure
end

function node = create_node(x, y)
node.x = x;
node.y = y;
node.successors = {};
end

function node = add_node_successor(node, successor)
node.successors{end+1} = successor;
end

function rec = create_record(node, cost_start, cost_finish, parent)
rec.node = node;
rec.cost_start = cost_start;
rec.cost_finish = cost_finish;
rec.cost_total = cost_start + cost_finish;
rec.parent = parent;
rec.closed = false;
end

function list = create_record_list()
list.open = 0;
list.size = 0;
list.records = {};
end

function list = add_record(list, record)
list.size = list.size + 1;
list.open = list.open + 1;
list.records{end+1} = record;
end

function list = close_record(list, record)
record.closed = true;
list.open = list.open - 1;
end

function d = distance(a, b)
dx = a.x - b.x;
dy = a.y - b.y;
d = sqrt(dx*dx + dy*dy);
end
