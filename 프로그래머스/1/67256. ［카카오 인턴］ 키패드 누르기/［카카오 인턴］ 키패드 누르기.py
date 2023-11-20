def solution(numbers, hand):
    answer = ''
    """
    1 2 3
    4 5 6
    7 8 9
    * 0 #
    """
    num_map = {
        1:(0,0), 2:(0,1), 3:(0,2),
        4:(1,0), 5:(1,1), 6:(1,2),
        7:(2,0), 8:(2,1), 9:(2,2),
        "*":(3,0), 0:(3,1), "#":(3,2)
    }
    locs = [(3,0),(3,2)] # *,#
    for num in numbers:
        target_loc = num_map[num]
        if num in (1,4,7):
            answer+="L"
            locs[0] = target_loc
        elif num in (3,6,9):
            answer+="R"
            locs[1] = target_loc
        else:
            ld = abs(locs[0][0]-target_loc[0]) + abs(locs[0][1]-target_loc[1]) 
            rd = abs(locs[1][0]-target_loc[0]) + abs(locs[1][1]-target_loc[1]) 
            if ld<rd:
                answer+="L"
                locs[0] = target_loc
            elif ld>rd:
                answer+="R"
                locs[1] = target_loc
            else:
                if hand =="left":
                    answer+="L"
                    locs[0] = target_loc
                else:
                    answer+="R"
                    locs[1] = target_loc
        
    return answer